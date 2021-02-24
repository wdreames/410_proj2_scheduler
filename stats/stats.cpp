/*
 * Stats.h
 *
 *  Created on: Feb 23, 2021
 *      Author: William Reames
 */
#include "../includes/stats.h"

using namespace std;

Stats::Stats(std::vector<PCB> &finished_vector) {
	vec = &finished_vector;
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo() {
	for (std::vector<PCB>::iterator it = vec->begin(); it != vec->end(); it++) {
		cout << "Process " << it->process_number;
		cout << " Required CPU time:" << it->required_cpu_time;
		cout << " arrived:" << it->arrival_time;
		cout << " started:" << it->start_time;
		cout << " finished:" << it->finish_time << "\n";
	}
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time() {
	float sum = 0;
	for (std::vector<PCB>::iterator it = vec->begin(); it != vec->end(); it++) {
		sum += it->start_time - it->arrival_time;
	}
	return vec->size() > 0 ? sum / vec->size() : 0;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time() {
	float sum = 0;
	for (std::vector<PCB>::iterator it = vec->begin(); it != vec->end(); it++) {
		sum += it->finish_time - it->arrival_time;
	}
	return vec->size() > 0 ? sum / vec->size() : 0;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time() {
	float sum = 0;
	for (std::vector<PCB>::iterator it = vec->begin(); it != vec->end(); it++) {
		sum += it->finish_time - it->arrival_time - it->required_cpu_time;
	}
	return vec->size() > 0 ? sum / vec->size() : 0;
}

//does the work (only needs to run once)
void Stats::calcStats() {
	av_response_time = Stats::get_av_response_time();
	av_turnaround_time = Stats::get_av_turnaround_time();
	av_wait_time = Stats::get_av_wait_time();
}
