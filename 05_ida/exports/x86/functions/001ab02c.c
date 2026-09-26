/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab02c. */
int __cdecl -[DriverCmdtr send:](DriverCmdtr *self, SEL a2, int a3)
{
  int ret; // ebx
  _DWORD v5[6]; // [esp+Ch] [ebp-18h] BYREF

  qmemcpy(v5, &unk_1D5D78, sizeof(v5)); /*0x1ab046*/
  objc_msgSend(self->_interLock, sel_lockWhen_, 3); /*0x1ab058*/
  self->_oper = a3; /*0x1ab060*/
  v5[1] = 24; /*0x1ab063*/
  v5[4] = self->_driverPort_kern; /*0x1ab06d*/
  v5[5] = 2302756; /*0x1ab070*/
  objc_msgSend(self->_interLock, sel_unlockWith_, 2); /*0x1ab087*/
  ret = msg_send_from_kernel(v5, 0, 0); /*0x1ab099*/
  if ( ret ) /*0x1ab0a0*/
  {
    objc_msgSend(self->_interLock, sel_lock); /*0x1ab0d2*/
  }
  else
  {
    objc_msgSend(self->_interLock, sel_lockWhen_, 1); /*0x1ab0b2*/
    ret = self->_ret; /*0x1ab0ba*/
  }
  objc_msgSend(self->_interLock, sel_unlockWith_, 3); /*0x1ab0ea*/
  return ret; /*0x1ab0f4*/
}
