/*
 * scheduler_FIFO.h
 *
 *  Created on: Sep 9, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include "../includes/scheduler_FIFO.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
	return false;
}

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort() {
	return;
}
