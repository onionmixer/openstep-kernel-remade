/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca694. */
Ivar __cdecl object_getInstanceVariable(id obj, const char *name, void **outValue)
{
  objc_ivar *v3; // edx
  Ivar InstanceVariable; // eax

  v3 = nullptr; /*0x1ca6a2*/
  if ( obj && name ) /*0x1ca6aa*/
  {
    InstanceVariable = class_getInstanceVariable(*(Class *)obj, name); /*0x1ca6b0*/
    v3 = InstanceVariable; /*0x1ca6b5*/
    if ( InstanceVariable ) /*0x1ca6b9*/
      *outValue = *(void **)((char *)obj + InstanceVariable->ivar_offset); /*0x1ca6c2*/
    else
      *outValue = nullptr; /*0x1ca6c8*/
  }
  return v3; /*0x1ca6d3*/
}
