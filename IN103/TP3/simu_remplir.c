#include <stdlib.h>

#include "body.h"
#include "simu.h"


/** A simple constant force. It does not depend on the position or speed.
    The coordinates of the computed force are returned by address in
    [fx] and [fy]. */
void f (double x, double y, double vx, double vy, double *fx, double *fy)
{
  *fx = 5.0 ;
  *fy = 5.0 ;
}


/** The array containing all the forces to apply to bodies. It must be
    NULL-terminated.
    We could imagine that all the forces do not apply on all the objects.
    In this case, make several arrays or link objects and forces. */
force_t forces_array[] = { f, NULL } ;


/** Apply all the forces of tha array [forces] onto the body [b]. This function
    simply update the acceleration from the applied force, the current
    acceleration of the body and its mass. It's indeed the second Newton's
    law. */
void apply_forces_on_body (struct body_t *b, force_t *forces)
{
  int i = 0;
  float m = b->mass;
  double fx;
  double fy;
  while (forces_array[i] != NULL)
  {
    (forces_array[i])(b->x, b->y, b->vx, b->vy, &fx, &fy);
    b->ax += *fx/m;
    b->ay += *fy/m;
    i++;
  }
}

/** Run all the forces on all the bodies. Add the gravity as a shortcut
    by setting the initial y acceleration to 1g. This is simpler than computing
    the force induced between the Earth and each object, then apply this force
    to compute the acceleration. */
void simulate_bodies (struct body_list_t *bl, force_t *forces)
{
  struct body_list_t* test = bl->next;
  while (test != NULL)
  {
    test->body->ax = 0;
    test->body->ay = -9.81;
    /*Update the accelerations*/
    apply_forces_on_body(test, forces_array);

    /*Update position and accelerations*/
    move_body(test);
    test = test->next;
  }
}