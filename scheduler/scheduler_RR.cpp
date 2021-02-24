/*
 * scheduler_RR.h
 *
 *  Created on: Feb 23, 2021
 *      Author: William Reames
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

//override base class behavior if necessary, otherwise call it
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	//Measures the time that the process has been on the processor
	int time_on_cpu = p.required_cpu_time - p.remaining_cpu_time;

	//If the process has been on the processor for a given slice of time, it is swapped off
	if (time_on_cpu != 0 && time_on_cpu % time_slice == 0) {
		return true;
	}
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR::sort() {
	return;
}
