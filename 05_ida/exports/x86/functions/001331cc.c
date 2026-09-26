/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1331cc. */
int async_daemon()
{
  int result; // eax
  int v1; // eax

  *(_DWORD *)(active_threads + 120) = 1; /*0x1331d4*/
  stack_privilege(active_threads); /*0x1331e2*/
  ++dword_1E59EC; /*0x1331e7*/
  if ( !setjmp((int *)(dword_1E875C + 40)) ) /*0x133200*/
  {
    while ( 1 ) /*0x13327c*/
    {
      ++dword_1E59E8; /*0x13327c*/
      while ( !async_bufhead ) /*0x133289*/
        sleep((unsigned int)&async_bufhead); /*0x133293*/
      --dword_1E59E8; /*0x1332a4*/
      v1 = async_bufhead; /*0x1332aa*/
      async_bufhead = *(_DWORD *)(async_bufhead + 12); /*0x1332b2*/
      sub_1332C8(v1); /*0x1332b9*/
    }
  }
  if ( dword_1E59EC ) /*0x133209*/
  {
    result = dword_1E59EC - 1; /*0x13323c*/
    dword_1E59EC = result; /*0x13323d*/
    --dword_1E59E8; /*0x133242*/
    if ( !result ) /*0x13324f*/
    {
      for ( result = async_bufhead; async_bufhead; result = async_bufhead ) /*0x133258*/
      {
        async_bufhead = *(_DWORD *)(result + 12); /*0x13325f*/
        sub_1332C8(result); /*0x133266*/
      }
    }
  }
  else
  {
    for ( result = async_bufhead; async_bufhead; result = async_bufhead ) /*0x133212*/
    {
      *(_BYTE *)result |= 4u; /*0x133218*/
      async_bufhead = *(_DWORD *)(result + 12); /*0x13321e*/
      biodone(result); /*0x133225*/
    }
  }
  return result; /*0x133238*/
}
