/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdb98. */
unsigned int __cdecl method_getSizeOfArguments(Method m)
{
  unsigned int v1; // ebx
  _BYTE *i; // ecx

  v1 = 0; /*0x1cdb9f*/
  for ( i = (_BYTE *)sub_1CD9A4(m->method_types); (unsigned __int8)(*i - 48) <= 9u; ++i ) /*0x1cdbaa*/
    v1 = (char)*i + 10 * v1 - 48; /*0x1cdbba*/
  return v1; /*0x1cdbc8*/
}
