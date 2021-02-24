/*
 * SchedulerSRTF.h
 *
 *  Created on: Feb 23, 2021
 *      Author: William Reames
 *
 *     implements SRTF scheduling algorithm
 *     pre-emptive
 */

#include <algorithm>
#include <vector>
#include "../includes/scheduler_SRTF.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	//If the next process has a shorter remaining time, the scheduler switches to that process
	if (p.remaining_cpu_time > ready_q->front().remaining_cpu_time) {
		return true;
	}
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//Helper method used for sorting the ready queue
bool sortByRemainingCPUTime(PCB i, PCB j) {
	return i.remaining_cpu_time < j.remaining_cpu_time;
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	//Converts the ready queue into a vector so that it is easier to sort
	std::vector<PCB> pcbs;
	while (!ready_q->empty()) {
		pcbs.push_back(ready_q->front());
		ready_q->pop();
	}

	//Sorts the vector
	std::sort(pcbs.begin(), pcbs.end(), sortByRemainingCPUTime);

	//Converts back to a queue
	for (std::vector<PCB>::iterator it = pcbs.begin(); it != pcbs.end(); it++) {
		ready_q->push(*it);
	}
}
