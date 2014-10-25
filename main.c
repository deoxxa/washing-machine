#include <stdio.h>
#include <stdlib.h>

#include "step.h"
#include "machine.h"

int main(int argc, char** argv) {
  int rc, i;
  machine_t machine;

  step_t steps[] = {
    {OP_PING, 0},
    {OP_HEAT, 30},
    {OP_FILL, 50},
    {OP_WAIT, 15},
    {OP_WASH, 25},
    {OP_WAIT, 15},
  };

  int c = sizeof(steps) / sizeof(step_t);

  printf("PROGRAM:\n\n");
  for (i=0;i<c;++i) {
    printf("[%02d] %s %d\n", i, op_names[steps[i].op], steps[i].arg);
  }
  printf("\n");

  printf("INITIALISING MACHINE...\n");
  rc = machine_init(&machine);
  if (rc != 0) {
    printf("ERROR INITIALISING MACHINE: %d\n", rc);
    exit(1);
  }
  printf("MACHINE INTIALISED!\n\n");

  printf("RUNNING PROGRAM...\n\n");
  for (i=0;i<c;++i) {
    printf("[%02d] %s %d\n", i, op_names[steps[i].op], steps[i].arg);

    rc = machine_run(&machine, &steps[i]);
    if (rc != 0) {
      printf("ERROR %d AT STEP %d (%d [%d])\n", rc, i, steps[i].op, steps[i].arg);
      exit(1);
    }

    printf("---- MACHINE STATE: HEAT=%d, WATER=%d, MODE=%d, SPEED=%d\n\n", machine.heat, machine.water, machine.mode, machine.speed);
  }
  printf("PROGRAM COMPLETE!\n");

  return 0;
}
