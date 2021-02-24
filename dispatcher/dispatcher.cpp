/*
 * Dispatcher.h
 *
 *  Created on: Feb 23, 2021
 *      Author: William Reames
 *
 *      moves processes on and off the CPU
 */

#include "../includes/dispatcher.h"

//pull current process (if any) off CPU and return it
//if nothing on CPU returns an uninitialized PCB
PCB Dispatcher::get_from_CPU() {
	PCB returnVal;
	if (Dispatcher::isValidJobOnCPU()) {
		returnVal = cpu->get_process_off_core();
	} else {
		returnVal.reset();
	}
	return returnVal;
}

//place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB &process) {
	cpu->put_process_on_core(process);
}

//is CPU idle or working
bool Dispatcher::isValidJobOnCPU() {
	PCB current_process = cpu->get_COPY_of_Current_Process();
	is_valid_job_on_cpu = !current_process.isEmpty();
	return is_valid_job_on_cpu;
}

