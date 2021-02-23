/*
 * scheduler_RR.h
 *
 *  Created on: Sep 9, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p){
	return false;
}

//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR::sort(){
	return;
}
