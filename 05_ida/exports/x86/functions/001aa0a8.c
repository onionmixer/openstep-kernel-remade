/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa0a8. */
int __cdecl -[DriverCmd send:](DriverCmd *self, SEL a2, int a3)
{
  int ret; // ebx
  _DWORD v5[6]; // [esp+Ch] [ebp-18h] BYREF

  qmemcpy(v5, &unk_1D5CB4, sizeof(v5)); /*0x1aa0c2*/
  objc_msgSend(self->_interLock, sel_lockWhen_, 3); /*0x1aa0d4*/
  self->_oper = a3; /*0x1aa0dc*/
  v5[1] = 24; /*0x1aa0df*/
  v5[4] = self->_driverPort_kern; /*0x1aa0e9*/
  v5[5] = 2302756; /*0x1aa0ec*/
  objc_msgSend(self->_interLock, sel_unlockWith_, 2); /*0x1aa103*/
  ret = msg_send_from_kernel(v5, 0, 0); /*0x1aa115*/
  if ( ret ) /*0x1aa11c*/
  {
    objc_msgSend(self->_interLock, sel_lock); /*0x1aa14e*/
  }
  else
  {
    objc_msgSend(self->_interLock, sel_lockWhen_, 1); /*0x1aa12e*/
    ret = self->_ret; /*0x1aa136*/
  }
  objc_msgSend(self->_interLock, sel_unlockWith_, 3); /*0x1aa166*/
  return ret; /*0x1aa170*/
}
