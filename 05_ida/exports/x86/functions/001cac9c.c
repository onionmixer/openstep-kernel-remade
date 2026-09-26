/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cac9c. */
_DWORD *__cdecl _NXAddHandler(int a1)
{
  thread_act_t v1; // edx
  _DWORD *result; // eax

  v1 = current_thread_EXTERNAL(); /*0x1caca8*/
  result = &unk_1E551C; /*0x1cacaa*/
  if ( &unk_1E551C ) /*0x1cacb1*/
  {
    while ( result[4] != v1 ) /*0x1cacb7*/
    {
      result = (_DWORD *)result[5]; /*0x1cacb9*/
      if ( !result ) /*0x1cacbe*/
        goto LABEL_4; /*0x1cacbe*/
    }
  }
  else
  {
LABEL_4:
    result = sub_1CA960(v1); /*0x1cacc0*/
  }
  *(_DWORD *)(a1 + 72) = *result; /*0x1cacc8*/
  *result = a1; /*0x1caccb*/
  *(_DWORD *)(a1 + 76) = 0; /*0x1caccd*/
  return result; /*0x1cacd4*/
}
