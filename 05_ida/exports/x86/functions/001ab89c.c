/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab89c. */
int __cdecl -[IOTokenRing outputPacket:address:](
        IOTokenRing *self,
        SEL a2,
        $199DFB5D1DF31DC82E78091AC4DEC886 *a3,
        void *a4)
{
  const char *v5; // eax
  int v6; // edx
  int v7; // esi
  const char *v8; // eax
  _BYTE *v9; // ebx
  int v10; // [esp-8h] [ebp-18h]

  if ( (*(_BYTE *)&self->_flags & 1) != 0 )
  {
    if ( self->_maxInfoFieldSize >= nb_size((int)a3) )
    {
      v6 = 0; /*0x1ab918*/
      if ( *((char *)a4 + 8) < 0 ) /*0x1ab91e*/
      {
        v6 = *((_BYTE *)a4 + 14) & 0x1F; /*0x1ab926*/
        if ( (*((_BYTE *)a4 + 14) & 1) != 0 || (unsigned int)(v6 - 2) > 0x10 ) /*0x1ab933*/
          v6 = -1; /*0x1ab935*/
      }
      if ( v6 >= 0 ) /*0x1ab93c*/
        v7 = v6 + 14; /*0x1ab944*/
      else
        v7 = v6; /*0x1ab93e*/
      if ( v7 >= 0 )
      {
        nb_grow_top((int)a3, v7); /*0x1ab976*/
        v9 = (_BYTE *)nb_map((int)a3); /*0x1ab981*/
        bcopy(a4, v9, v7); /*0x1ab989*/
        *v9 &= 0xF0u; /*0x1ab98e*/
        -[IOTokenRing transmit:](self, sel_transmit_, a3); /*0x1ab99d*/
        return 0; /*0x1ab9a2*/
      }
      else
      {
        v8 = -[IODevice name](self, sel_name); /*0x1ab956*/
        IOLog((int)"%s: bad mac header\n", v8);
        nb_free((int)a3); /*0x1ab967*/
        return 40; /*0x1ab96c*/
      }
    }
    else
    {
      v10 = nb_size((int)a3); /*0x1ab8e6*/
      v5 = -[IODevice name](self, sel_name); /*0x1ab8f2*/
      IOLog((int)"%s: netOutput bad frame size=%d\n", v5, v10);
      nb_free((int)a3); /*0x1ab906*/
      return 40; /*0x1ab90b*/
    }
  }
  else
  {
    nb_free((int)a3); /*0x1ab8bb*/
    return 50; /*0x1ab8c0*/
  }
}
