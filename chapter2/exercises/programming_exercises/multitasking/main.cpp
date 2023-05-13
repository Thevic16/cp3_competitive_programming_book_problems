#include <bits/stdc++.h>

using namespace std;

// https://vjudge.net/problem/UVA-11926

/*
 Reference:
 https://github.com/ajahuang/UVa/blob/master/UVa%2011926%20-%20Multitasking.cpp
 */

bitset<1000001> schedule;

struct OneTimeTask {
    int start;
    int end;
};

struct RepeatingTask {
    int start;
    int end;
    int interval;
};

bool conflictOneTimeTasks(vector<OneTimeTask> oneTimeTasks) {
    bool conflict = false;

    for (OneTimeTask task: oneTimeTasks){
        for (int i = task.start+1; i <= task.end; ++i) {
            if(schedule.test(i)){
                conflict = true;
                return conflict;
            }
            else {
                schedule.set(i);
            }
        }
    }

    return conflict;
}

bool conflictRepeatingTasks(vector<RepeatingTask> repeatingTasks) {
    bool conflict = false;

    for (RepeatingTask task: repeatingTasks){
        while(task.end <= 1000000){
            for (int i = task.start+1; i <= task.end; ++i) {
                if(schedule.test(i)){
                    conflict = true;
                    return conflict;
                }
                else {
                    schedule.set(i);
                }
            }

            task.start += task.interval;
            task.end += task.interval;
        }

    }

    return conflict;
}

int main() {
    int n,m;

    while(cin >> n >> m, !(n == 0 && m == 0)){
        vector<OneTimeTask> oneTimeTasks;
        vector<RepeatingTask> repeatingTasks;

        for (int i = 0; i < n; ++i) {
            int start;
            int end;
            cin >> start >> end;
            OneTimeTask task;
            task.start = start;
            task.end = end;

            oneTimeTasks.push_back(task);
        }

        for (int i = 0; i < m; ++i) {
            int start;
            int end;
            int interval;
            cin >> start >> end >> interval;
            RepeatingTask task;
            task.start = start;
            task.end = end;
            task.interval = interval;

            repeatingTasks.push_back(task);
        }

        if(!conflictOneTimeTasks(oneTimeTasks) && !conflictRepeatingTasks(repeatingTasks)){
            cout << "NO CONFLICT" << endl;
        }
        else {
            cout << "CONFLICT" << endl;
        }

        schedule.reset();
    }

    return 0;
}
