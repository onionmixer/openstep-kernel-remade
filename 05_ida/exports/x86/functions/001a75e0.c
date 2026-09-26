/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a75e0. */
id __cdecl volCheckRegister(id a1, __int16 a2, __int16 a3)
{
  if ( (unsigned __int8)objc_msgSend(a1, sel_isPhysical) ) /*0x1a75f9*/
    return sub_1A76A4(0, (int)a1, 0, a2, a3); /*0x1a762d*/
  objc_msgSend(a1, sel_name); /*0x1a760d*/
  return (id)IOLog("volCheckRegister: %s is not a physical device\n");
}
