/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161f4c. */
int __cdecl kdp_packet(void *a1, size_t *a2)
{
  size_t v2; // ebx
  unsigned int v4; // edx
  int v5; // ebx
  char v6; // [esp+10h] [ebp-604h] BYREF
  unsigned __int8 v7; // [esp+11h] [ebp-603h]
  unsigned __int16 v8; // [esp+12h] [ebp-602h]
  int v9; // [esp+14h] [ebp-600h]

  v2 = *a2; /*0x161f61*/
  bcopy(a1, &v6, 0x604u); /*0x161f6d*/
  if ( v2 > 7 && v8 == v2 ) /*0x161f89*/
  {
    if ( v6 >= 0 ) /*0x161fac*/
    {
      v4 = v6 & 0x7F; /*0x161fcc*/
      if ( v4 <= 0xE ) /*0x161fd2*/
      {
        v5 = ((int (__cdecl *)(char *))funcs_162009[v4])(&v6); /*0x16200b*/
        bcopy(&v6, a1, *a2); /*0x162015*/
        return v5; /*0x16201a*/
      }
      else
      {
        safe_prf("kdp_packet bad request %x len %d seq %x key %x\n", v4, v8, v7, v9); /*0x161ff0*/
        return 0; /*0x161ff5*/
      }
    }
    else
    {
      safe_prf("kdp_packet reply recvd req %x seq %x\n", v6 & 0x7F, v7); /*0x161fc1*/
      return 0; /*0x161fc6*/
    }
  }
  else
  {
    safe_prf("kdp_packet bad len pkt %d hdr %d\n", v2, v8); /*0x161f99*/
    return 0; /*0x161f9e*/
  }
}
