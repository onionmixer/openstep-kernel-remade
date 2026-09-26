/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1abaec. */
id __cdecl -[IOSCSIController initFromDeviceDescription:](IOSCSIController *self, SEL a2, id a3)
{
  id v3; // eax
  unsigned int v5; // edx
  int v6; // [esp-10h] [ebp-44h]
  objc_super v7; // [esp+8h] [ebp-2Ch] BYREF
  unsigned int v8; // [esp+10h] [ebp-24h] BYREF
  unsigned int v9; // [esp+14h] [ebp-20h]
  unsigned int v10; // [esp+18h] [ebp-1Ch]
  unsigned int v11; // [esp+1Ch] [ebp-18h]
  char v12[20]; // [esp+20h] [ebp-14h] BYREF

  self->_reserveQ.prev = (queue_entry *)&self->_reserveQ; /*0x1abafd*/
  self->_reserveQ.next = (queue_entry *)&self->_reserveQ; /*0x1abb03*/
  v3 = -[Object class](self, sel_class); /*0x1abb18*/
  if ( objc_msgSend(v3, sel_deviceStyle) ) /*0x1abb21*/
    goto LABEL_6; /*0x1abb21*/
  v7.receiver = self; /*0x1abb38*/
  v7.super_class = (Class)stru_1FA334.ext; /*0x1abb41*/
  if ( !-[IODirectDevice initFromDeviceDescription:](&v7, sel_initFromDeviceDescription_, a3) ) /*0x1abb48*/
    return nullptr; /*0x1abb56*/
  if ( !-[IODirectDevice startIOThread](self, sel_startIOThread) ) /*0x1abb64*/
  {
LABEL_6:
    -[IODevice setUnit:](self, sel_setUnit_, dword_1E516C); /*0x1abb93*/
    v6 = dword_1E516C++; /*0x1abb9e*/
    sprintf(v12, "sc%d", v6); /*0x1abbae*/
    -[IODevice setName:](self, sel_setName_, v12); /*0x1abbbc*/
    -[IODevice setDeviceKind:](self, sel_setDeviceKind_, "sc"); /*0x1abbd1*/
    -[IOSCSIController getDMAAlignment:](self, sel_getDMAAlignment_, &v8); /*0x1abbe2*/
    v5 = v8; /*0x1abbe7*/
    self->_worstCaseAlign = v8; /*0x1abbea*/
    if ( v9 > v5 ) /*0x1abbf5*/
      self->_worstCaseAlign = v9; /*0x1abbf7*/
    if ( self->_worstCaseAlign < v10 ) /*0x1abc06*/
      self->_worstCaseAlign = v10; /*0x1abc08*/
    if ( self->_worstCaseAlign < v11 ) /*0x1abc17*/
      self->_worstCaseAlign = v11; /*0x1abc19*/
    if ( self->_worstCaseAlign == 1 ) /*0x1abc26*/
      self->_worstCaseAlign = 0; /*0x1abc28*/
    return self; /*0x1abc32*/
  }
  else
  {
    -[IOSCSIController free](self, sel_free); /*0x1abb78*/
    return nullptr; /*0x1abb7d*/
  }
}
