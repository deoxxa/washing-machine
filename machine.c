#include "step.h"
#include "machine.h"

int machine_init(machine_t* machine) {
  machine->heat = 0;
  machine->water = 0;
  machine->mode = 0;
  machine->speed = 0;

  return 0;
}

int machine_run_null(machine_t* machine, step_t* step) {
  return 0;
}

int machine_run_ping(machine_t* machine, step_t* step) {
  return 0;
}

int machine_run_wait(machine_t* machine, step_t* step) {
  return 0;
}

int machine_run_heat(machine_t* machine, step_t* step) {
  machine->heat = step->arg;

  return 0;
};

int machine_run_fill(machine_t* machine, step_t* step) {
  machine->water = step->arg;

  return 0;
}

int machine_run_wash(machine_t* machine, step_t* step) {
  machine->mode = 1;
  machine->speed = step->arg;

  return 0;
}

int machine_run_spin(machine_t* machine, step_t* step) {
  machine->mode = 2;
  machine->speed = step->arg;

  return 0;
}

int machine_run_stop(machine_t* machine, step_t* step) {
  machine->mode = 0;
  machine->speed = 0;

  return 0;
}

int machine_run(machine_t* machine, step_t* step) {
  switch (step->op) {
    case OP_NULL:
      return machine_run_null(machine, step);
    case OP_PING:
      return machine_run_ping(machine, step);
    case OP_WAIT:
      return machine_run_wait(machine, step);
    case OP_HEAT:
      return machine_run_heat(machine, step);
    case OP_FILL:
      return machine_run_fill(machine, step);
    case OP_WASH:
      return machine_run_wash(machine, step);
    case OP_SPIN:
      return machine_run_spin(machine, step);
    case OP_STOP:
      return machine_run_stop(machine, step);
  }

  return -1;
}
