#ifndef _MACHINE_H
#define _MACHINE_H

typedef struct machine_s {
  int heat;
  int water;
  int mode;
  int speed;
} machine_t;

int machine_init(machine_t* machine);
int machine_run_null(machine_t* machine, step_t* step);
int machine_run_ping(machine_t* machine, step_t* step);
int machine_run_wait(machine_t* machine, step_t* step);
int machine_run_heat(machine_t* machine, step_t* step);
int machine_run_fill(machine_t* machine, step_t* step);
int machine_run_wash(machine_t* machine, step_t* step);
int machine_run_spin(machine_t* machine, step_t* step);
int machine_run_stop(machine_t* machine, step_t* step);
int machine_run(machine_t* machine, step_t* step);

#endif
