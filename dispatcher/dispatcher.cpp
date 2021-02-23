/*
 * Dispatcher.h
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 *
 *      moves processes on and off the CPU
 */

#include "../includes/dispatcher.h"

//pull current process (if any) off CPU and return it
//if nothing on CPU returns an uninitialized PCB
PCB Dispatcher::get_from_CPU(){
	PCB returnVal;
	returnVal.reset();
	return returnVal;
}

//place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB  &process){
	return;
}

//is CPU idle or working
bool Dispatcher::isValidJobOnCPU(){
	return false;
}

