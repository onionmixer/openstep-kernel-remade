/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa178. */
id __cdecl -[IOEthernet initFromDeviceDescription:](IOEthernet *self, SEL a2, id a3)
{
  DriverCmd *v4; // eax
  int v5; // esi
  char v6[8]; // [esp+Ch] [ebp-10h] BYREF
  objc_super v7; // [esp+14h] [ebp-8h] BYREF

  v7.receiver = self; /*0x1aa18f*/
  v7.super_class = (Class)stru_1FA294.ext; /*0x1aa198*/
  if ( !-[IODirectDevice initFromDeviceDescription:](&v7, sel_initFromDeviceDescription_, a3) ) /*0x1aa19f*/
    return nullptr; /*0x1aa1ab*/
  if ( -[IODirectDevice startIOThread](self, sel_startIOThread) ) /*0x1aa1bc*/
  {
    -[IOEthernet free](self, sel_free); /*0x1aa1d0*/
    return nullptr; /*0x1aa1d5*/
  }
  else
  {
    -[IODirectDevice interruptPort](self, sel_interruptPort); /*0x1aa1e4*/
    v4 = +[Object alloc](aDrivercmd, sel_alloc); /*0x1aa1ff*/
    self->_driverCmd = -[DriverCmd initPort:](v4, sel_initPort_); /*0x1aa20d*/
    self->_multiLock = +[Object new](aNxlock, sel_new); /*0x1aa226*/
    self->_multicastQueue.prev = (queue_entry *)&self->_multicastQueue; /*0x1aa232*/
    self->_multicastQueue.next = (queue_entry *)&self->_multicastQueue; /*0x1aa238*/
    v5 = dword_1E86FC++; /*0x1aa23e*/
    sprintf(v6, "%s%d", "en", v5); /*0x1aa259*/
    -[IODevice setName:](self, sel_setName_, v6); /*0x1aa26a*/
    -[IODevice setDeviceKind:](self, sel_setDeviceKind_, aEthernet); /*0x1aa27c*/
    -[IODevice setUnit:](self, sel_setUnit_, v5); /*0x1aa28a*/
    -[IODevice registerDevice](self, sel_registerDevice); /*0x1aa29a*/
    return self; /*0x1aa29f*/
  }
}
