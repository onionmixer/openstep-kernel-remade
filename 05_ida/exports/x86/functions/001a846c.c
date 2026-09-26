/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a846c. */
id __cdecl -[IODirectDevice free](IODirectDevice *self, SEL a2)
{
  id v2; // eax
  int v3; // eax
  int v4; // eax
  id v5; // eax
  int interruptPort; // [esp-Ch] [ebp-40h]
  int *busPrivate; // [esp+Ch] [ebp-28h]
  id *v9; // [esp+10h] [ebp-24h]
  objc_super v10; // [esp+14h] [ebp-20h] BYREF
  _DWORD v11[6]; // [esp+1Ch] [ebp-18h] BYREF

  v9 = (id *)self->_private; /*0x1a847e*/
  busPrivate = (int *)self->_busPrivate; /*0x1a8487*/
  qmemcpy(v11, &unk_1D5C60, sizeof(v11)); /*0x1a8498*/
  if ( self->_interruptPort ) /*0x1a849a*/
  {
    if ( self->_ioThread ) /*0x1a84a3*/
    {
      v11[1] = 24; /*0x1a84ac*/
      v11[5] = 2302774; /*0x1a84b3*/
      v11[4] = IOGetKernPort(self->_interruptPort); /*0x1a84c6*/
      msg_send_from_kernel(v11, 0, 0); /*0x1a84d1*/
    }
    v2 = objc_msgSend(self->_deviceDescriptionDelegate, sel_device); /*0x1a84ee*/
    objc_msgSend(v2, sel_detachInterruptPort); /*0x1a84f7*/
    interruptPort = self->_interruptPort; /*0x1a8502*/
    v3 = task_self(); /*0x1a8503*/
    port_deallocate_EXTERNAL(v3, interruptPort); /*0x1a8509*/
    self->_interruptPort = 0; /*0x1a850e*/
  }
  if ( busPrivate ) /*0x1a851f*/
  {
    v4 = *busPrivate; /*0x1a8524*/
    if ( *busPrivate == 1 ) /*0x1a8529*/
    {
      -[IODirectDevice freeEISA](self, sel_freeEISA); /*0x1a8531*/
    }
    else if ( v4 == 2 ) /*0x1a8537*/
    {
      -[IODirectDevice freeHPPA](self, aFreehppa); /*0x1a853f*/
    }
    else if ( v4 == 3 ) /*0x1a8547*/
    {
      -[IODirectDevice freeSPARC](self, aFreesparc); /*0x1a8551*/
    }
  }
  if ( v9 ) /*0x1a855d*/
  {
    if ( *v9 ) /*0x1a8562*/
      objc_msgSend(*v9, sel_free); /*0x1a8570*/
    v5 = v9[1]; /*0x1a857b*/
    if ( v5 ) /*0x1a8580*/
      objc_msgSend(v5, sel_free); /*0x1a858a*/
    IOFree((int)v9, 8); /*0x1a8598*/
  }
  v10.receiver = self; /*0x1a85a7*/
  v10.super_class = (Class)stru_1FA1A4.super_class; /*0x1a85b0*/
  return -[IODevice free](&v10, sel_free); /*0x1a85bf*/
}
