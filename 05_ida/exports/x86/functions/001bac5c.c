/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bac5c. */
int __cdecl -[AudioCommand send:](AudioCommand *self, SEL a2, int a3)
{
  int ret; // ebx
  _DWORD v5[6]; // [esp+Ch] [ebp-18h] BYREF

  qmemcpy(v5, &unk_1D5E94, sizeof(v5)); /*0x1bac76*/
  objc_msgSend(self->interLock, sel_lockWhen_, 3); /*0x1bac88*/
  self->command = a3; /*0x1bac90*/
  v5[1] = 24; /*0x1bac93*/
  v5[4] = self->driverPort_kern; /*0x1bac9d*/
  v5[5] = 902; /*0x1baca0*/
  objc_msgSend(self->interLock, sel_unlockWith_, 2); /*0x1bacb7*/
  ret = msg_send_from_kernel(v5, 1, 1000); /*0x1baccc*/
  if ( ret ) /*0x1bacd3*/
  {
    objc_msgSend(self->interLock, sel_lock); /*0x1bad06*/
  }
  else
  {
    objc_msgSend(self->interLock, sel_lockWhen_, 1); /*0x1bace5*/
    ret = self->ret; /*0x1baced*/
  }
  objc_msgSend(self->interLock, sel_unlockWith_, 3); /*0x1bad1e*/
  return ret; /*0x1bad28*/
}
