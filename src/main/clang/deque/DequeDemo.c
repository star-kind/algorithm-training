#include "../../head/export_index.h"

#define maxsize 10

typedef struct {
  int *base;
  int front;
  int rear;
  int size;
} de_dequeue;

void initialize_deque(de_dequeue *q) {
  q->base = (int *)malloc(maxsize * sizeof(int));

  q->front = q->rear = 0;
  q->size = maxsize;
}

bool is_empty_deque(de_dequeue *q) {
  return q->rear == q->front ? true : false;
}

bool is_full_deque(de_dequeue *q) {
  return (q->rear + 1) % q->size == q->front ? true : false;
}

bool push_into_head(de_dequeue *q, int element) {
  if (is_full_deque(q) == true) {
    printf("queue has fulled\n");
    return false;
  }

  *(q->base + q->rear) = element;
  q->rear = (q->rear + 1) % q->size;

  return true;
}

bool pop_deque_rear(de_dequeue *q) {
  // judge whether it is empty
  if (is_empty_deque(q) == true) {
    printf("queue has already empty");
    return false;
  }

  // value of '*(deDequeue.base+deDequeue.rear)' is zero
  q->rear = (q->rear - 1) % maxsize;

  int e = *(q->base + q->rear);
  printf("eject value:  %d\n", e);

  return true;
}

void traver_queue(de_dequeue *q) {
  int index = q->front;

  while (index != q->rear) {
    printf("%d ", *(q->base + index));
    index = ++index % q->size;
  }
  printf("\n");
}

void export_deque_demo() {
  int y = 2;

  de_dequeue deDequeue;
  initialize_deque(&deDequeue);

  for (int i = 0; i < maxsize; ++i) {
    push_into_head(&deDequeue, y);
    y += 2;
  }
  traver_queue(&deDequeue);

  pop_deque_rear(&deDequeue);
  traver_queue(&deDequeue);
}