/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196878. */
int __cdecl -[kmDevice drawRect:](kmDevice *self, SEL a2, const km_drawrect *a3)
{
  unsigned __int16 v4; // ax
  int v5; // esi
  int v6; // ebx
  int v7; // [esp+Ch] [ebp-Ch] BYREF
  int v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v7 = *(_DWORD *)a3; /*0x196889*/
  v8 = *((_DWORD *)a3 + 1); /*0x19688f*/
  v9 = *((_DWORD *)a3 + 2); /*0x196895*/
  if ( self->fbMode == 3 ) /*0x19689f*/
    return 16; /*0x1968a1*/
  LOBYTE(v7) = v7 & 0xFC; /*0x1968a8*/
  v4 = v8 + 3; /*0x1968b0*/
  LOBYTE(v4) = (v8 + 3) & 0xFC; /*0x1968b4*/
  LOWORD(v8) = v4; /*0x1968b6*/
  v5 = HIWORD(v8) * (v4 >> 2); /*0x1968c7*/
  v9 = kalloc(v5); /*0x1968d0*/
  if ( copyin(*((_DWORD *)a3 + 2), v9, v5) ) /*0x1968d9*/
    v6 = -1; /*0x1968e5*/
  else
    v6 = (*((int (__cdecl **)($8EF4127CF77ECA3DDB612FCF233DC3A8 *, int *))self->fbp[0] + 3))(self->fbp[0], &v7); /*0x1968fc*/
  kfree(v9, v5); /*0x196906*/
  return v6; /*0x196910*/
}
