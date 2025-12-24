#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;

const ll MAX_SUBTASKS = 305;
const ll MAX_TIME = 1805;

struct Subtask {
    ll time_required;  // Time required for the subtask
    ll score;          // Score of the subtask
    ll dependency_count;  // Number of dependencies
    vector<int> dependencies;  // List of dependent subtasks
};

// Global variables
ll total_tasks, total_time;  // Total tasks and available time
ll dp[MAX_SUBTASKS][MAX_TIME];  // DP table: dp[subtask][time]
vector<Subtask> tasks[3];  // For 3 different tasks

void initialize_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
}

// Function to process input for a single task and fill subtask details
void input_subtask(Subtask &subtask) {
    cin >> subtask.time_required >> subtask.score >> subtask.dependency_count;
    subtask.dependencies.clear();  // Clear previous dependencies
    for (int j = 0; j < subtask.dependency_count; j++) {
        int dependency;
        cin >> dependency;  // Read the dependencies for this subtask
        subtask.dependencies.push_back(dependency);
    }
}

ll solve_task(vector<Subtask> &task, int num_subtasks, ll available_time) {
    memset(dp, 0, sizeof(dp));  // Initialize DP table
    
    // Process subtasks respecting dependencies (dynamic programming)
    for (int i = 1; i <= num_subtasks; ++i) {
        for (int time = available_time; time >= task[i-1].time_required; --time) {
            bool can_solve = true;
            
            // Check if all dependencies of task[i-1] are solved
            for (int dep : task[i-1].dependencies) {
                if (dp[dep][time - task[i-1].time_required] == 0) {
                    can_solve = false;
                    break;
                }
            }

            // If we can solve this subtask, update the DP table
            if (can_solve) {
                for (int t = available_time; t >= task[i-1].time_required; --t) {
                    dp[i][t] = max(dp[i][t], dp[i-1][t - task[i-1].time_required] + task[i-1].score);
                }
            }
        }
    }

    // Find the maximum score in the DP table
    ll max_score = 0;
    for (int t = 0; t <= available_time; ++t) {
        max_score = max(max_score, dp[num_subtasks][t]);
    }
    return max_score;
}

void solve() {
    cin >> total_time;  // Total available time for all tasks
    for (int task_idx = 0; task_idx < 3; ++task_idx) {
        int num_subtasks;
        cin >> num_subtasks;  // Number of subtasks for the current task
        tasks[task_idx].clear();

        for (int i = 0; i < num_subtasks; ++i) {
            Subtask subtask;
            input_subtask(subtask);
            tasks[task_idx].push_back(subtask);
        }

        // Solve the current task and print the result
        cout << solve_task(tasks[task_idx], num_subtasks, total_time) << endl;
    }
}

int main() {
    initialize_io();
    solve();
    return 0;
}
