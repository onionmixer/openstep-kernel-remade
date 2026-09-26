/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b62ac. */
void __cdecl -[IOAudio _dataPendingForChannel:](IOAudio *self, SEL a2, id a3)
{
  int v3; // eax
  int v4; // eax

  if ( !self->_dataPendingMessage ) /*0x1b62b3*/
  {
    v3 = IOMalloc(0x18u); /*0x1b62be*/
    self->_dataPendingMessage = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)v3; /*0x1b62c3*/
    *(_BYTE *)(v3 + 3) = 1; /*0x1b62c9*/
    *((_DWORD *)self->_dataPendingMessage + 1) = 24; /*0x1b62d3*/
    *((_DWORD *)self->_dataPendingMessage + 2) = 0; /*0x1b62e0*/
    *((_DWORD *)self->_dataPendingMessage + 3) = 0; /*0x1b62ed*/
    *((_DWORD *)self->_dataPendingMessage + 4) = self->_commandPort; /*0x1b6300*/
  }
  if ( (unsigned __int8)objc_msgSend(a3, sel_isRead) ) /*0x1b6311*/
    *((_DWORD *)self->_dataPendingMessage + 5) = 901; /*0x1b6323*/
  else
    *((_DWORD *)self->_dataPendingMessage + 5) = 900; /*0x1b6332*/
  v4 = msg_send_from_kernel(self->_dataPendingMessage, 1, 1000); /*0x1b6347*/
  if ( v4 )
  {
    if ( v4 != -103 )
      IOLog("Audio: data pending msg_send error: %d\n");
  }
}
