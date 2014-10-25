#ifndef _STEP_H
#define _STEP_H

const char *op_names[8];

typedef enum op_e {
  OP_NULL,
  OP_PING,
  OP_WAIT,
  OP_HEAT,
  OP_FILL,
  OP_WASH,
  OP_SPIN,
  OP_STOP
} op_t;

typedef struct step_s {
  op_t op;
  int  arg;
} step_t;

#endif
