
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node node;
struct node {
	int data;
	node * link;
};

void insert_at_end(node * head, int data);
node * clean(node * head);
void show(node const * head);

int main() {
  node * head = malloc(sizeof(node));
  if (head == NULL) {
    printf("malloc failed to allocate the %zu bytes needed for a node\n", sizeof(node));
    exit(EXIT_FAILURE);
  }
  head->data = 45;
  head->link = NULL;

  show(head);

  insert_at_end(head, 50);
  insert_at_end(head, 55);
  insert_at_end(head, 60);

  show(head);

  head = clean(head);

  show(head);

  return 0;
}

node * clean(node * head) {
  if (head != NULL) {
    node * lk = head;
    while (true) {
      node * next = lk->link;
      printf("deleting node %18p->link[%18p]\n", lk, lk->link);
      free(lk);
      lk = next;
      if (lk == NULL) {
        break;
      }
    }
    head = (node *) NULL;
  }
  return head;
}

void show(node const * head) {
  puts("--- show ----------------------------------------");
  if (head != NULL) {
    node const * lk = head;
    while (true) {
      printf("%18p: %18p - %4d\n", lk, lk->link, lk->data);
      if (lk->link == NULL) {
        break;
      }
      else {
        lk = lk->link;
      }
    }
    putchar('\n');
  }
  else {
    puts("Nothing to show\n");
  }
}

void insert_at_end(node * head, int data) {
  if (head != NULL) {
    //  find end node
    node * lk = head;
    while (lk->link != NULL) {
      lk = lk->link;
    }

    // create a new node
    lk->link = malloc(sizeof(node));
    if (lk->link == NULL) {
      printf("malloc failed to allocate the %zu bytes needed for a node\n", sizeof(node));
      exit(EXIT_FAILURE);
    }
    lk = lk->link;
    lk->data = data;
    lk->data = data;
  }

  return;
}
