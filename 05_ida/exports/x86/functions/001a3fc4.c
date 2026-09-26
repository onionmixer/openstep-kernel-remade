/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a3fc4. */
void __cdecl +[IODevice registerClass:](id a1, SEL a2, id a3)
{
  id *v3; // esi
  int v4; // eax

  v3 = (id *)IOMalloc(28); /*0x1a3fd3*/
  *v3 = a3; /*0x1a3fd5*/
  v3[3] = (id)-1; /*0x1a3fd7*/
  v3[2] = (id)-1; /*0x1a3fde*/
  v3[4] = nullptr; /*0x1a3fe5*/
  objc_msgSend(dword_1E8684, sel_lock); /*0x1a3ffa*/
  v3[1] = (id)dword_1E8678++; /*0x1a4005*/
  if ( (int *)dword_1E867C == &dword_1E867C ) /*0x1a401b*/
  {
    dword_1E867C = (int)v3; /*0x1a401d*/
    dword_1E8680 = (int)v3; /*0x1a4023*/
    v3[5] = &dword_1E867C; /*0x1a4029*/
    v3[6] = &dword_1E867C; /*0x1a4030*/
  }
  else
  {
    v4 = dword_1E8680; /*0x1a403c*/
    v3[6] = (id)dword_1E8680; /*0x1a4041*/
    v3[5] = &dword_1E867C; /*0x1a4044*/
    dword_1E8680 = (int)v3; /*0x1a404b*/
    *(_DWORD *)(v4 + 20) = v3; /*0x1a4051*/
  }
  objc_msgSend(dword_1E8684, sel_unlock); /*0x1a4062*/
}
