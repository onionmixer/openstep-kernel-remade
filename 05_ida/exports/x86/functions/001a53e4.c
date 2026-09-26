/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a53e4. */
id __cdecl +[IOConfigTable newForConfigData:](id a1, SEL a2, const char *a3)
{
  _DWORD *v3; // esi
  signed int v4; // edi
  char *v5; // ebx

  v3 = objc_msgSend(a1, sel_alloc); /*0x1a53fa*/
  v4 = strlen(a3) + 1; /*0x1a5407*/
  if ( v4 > 4096 ) /*0x1a5416*/
    v4 = 4096; /*0x1a5418*/
  v5 = (char *)IOMalloc(v4); /*0x1a5423*/
  bcopy(a3, v5, v4 - 1); /*0x1a542e*/
  v5[v4 - 1] = 0; /*0x1a5433*/
  v3[1] = v5; /*0x1a5438*/
  return v3; /*0x1a5440*/
}
