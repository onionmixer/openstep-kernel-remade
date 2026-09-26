
/* WARNING: Unknown calling convention */

token_address_bytes * FUN_001ab830(token_address_bytes *result_buffer,void *receiver,void *selector)

{
  *(undefined4 *)result_buffer->bytes = *(undefined4 *)((int)receiver + 0x13c);
  *(undefined2 *)(result_buffer->bytes + 4) = *(undefined2 *)((int)receiver + 0x140);
  return result_buffer;
}

