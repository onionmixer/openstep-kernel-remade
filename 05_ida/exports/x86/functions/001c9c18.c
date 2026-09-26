/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9c18. */
id __cdecl +[Object new](id a1, SEL a2)
{
  id v2; // edx

  v2 = _alloc((Class)a1, 0); /*0x1c9c29*/
  if ( *(int *)(*(_DWORD *)a1 + 12) > 1 ) /*0x1c9c34*/
    return objc_msgSend(v2, sel_init); /*0x1c9c44*/
  else
    return v2; /*0x1c9c36*/
}
