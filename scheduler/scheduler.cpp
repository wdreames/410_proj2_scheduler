/*
 * Scheduler.h
 *
 *  Created on: Sep 7, 2019
 *      Author: keiths to run next and
 *
 *      Chooses which process to run next also determines when its time to switch processes
 */

#include "../includes/scheduler.h"

//add a process, either a new one or one that
//had been running on the CPU and has been preempted
void Scheduler::add(PCB p){
	return;
}

//get next process
PCB Scheduler::getNext(){
	PCB returnVal;
	returnVal.reset();
	return returnVal;
}

//returns true if there are no  jobs in the readyQ
//false otherwise
bool Scheduler::isEmpty(){
	return false;
}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	return false;
}
