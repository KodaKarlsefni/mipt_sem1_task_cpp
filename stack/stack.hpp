const char* CopyStr(const char* str) {
  int len = 0;
  while (str[len] != '\0') {
    ++len;
  }
  char* copy = new char[len + 1];
  for (int i = 0; i <= len; ++i) {
    copy[i] = str[i];
  }
  return copy;
}

struct Node {
  const char* value;
  Node* next;
};

struct Stack {
  Node* head = nullptr;
  int size = 0;
};

void Push(Stack* stack, const char* str) {
  Node* new_node = new Node;
  new_node->value = CopyStr(str);
  new_node->next = stack->head;
  stack->head = new_node;
  stack->size += 1;
}

void Pop(Stack* stack) {
  if (stack->head == nullptr) {
    return;
  }
  Node* new_head = stack->head->next;
  delete[] stack->head->value;
  delete stack->head;
  stack->head = new_head;
  stack->size -= 1;
}

const char* Top(const Stack* stack) {
  if (stack->head == nullptr) {
    return nullptr;
  }
  return stack->head->value;
}

int Size(const Stack* stack) {
  return stack->size;
}

void Clear(Stack* stack) {
  while (stack->head != nullptr) {
    Pop(stack);
  }
}
