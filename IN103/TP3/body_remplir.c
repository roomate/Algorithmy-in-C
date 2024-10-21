#include <stdlib.h>
#include "body.h"

/** Integration delta time in seconds. */
#define DT (0.05)



/** Create and register in a linked list a new body. [l] is the linked list
    of bodies where to add this body. The other parameters are the various
    properties of the body.
    This function return the new head of bodies linked list. */
struct body_list_t* new_body (struct body_list_t* l, int color, int radius,
                              double mass,
                              double x, double y, double vx, double vy)
{
  /*Static memory allocation*/
  struct body_list_t* new = malloc(sizeof(body_list_t));
  if (new == NULL) {return NULL;}
  new->next = l;

  struct body_t body;
  body.vx = vx;
  body.vy = vy;
  body.x = x;
  body.y = y;
  body.radius = radius;
  body.mass = mass;
  body.color = color;

  new->body = &body;
  return new;
}

/** Move a body according to its current acceleration and speed.
    This function updates the [vx], [vy], [x], [y] components. It simply
    integrate acceleration and speed. */
void move_body (struct body_t *b)
{
  b->vx = b->vx + DT*b->ax;
  b->vy = b->vy + DT*b->ay;

  b->x = b->x + DT*b->vx ;
  b->y = b->y + DT*b->vy ;

}
