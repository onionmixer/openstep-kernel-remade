/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124a60. */
int sub_124A60()
{
  int result; // eax
  int v1; // [esp+0h] [ebp-40h]
  _BYTE v2[56]; // [esp+8h] [ebp-38h] BYREF

  result = 0; /*0x124a68*/
  if ( !dword_1DBAAC ) /*0x124a71*/
  {
    qmemcpy(v2, (const void *)(dword_1E875C + 40), sizeof(v2)); /*0x124a85*/
    result = alert(60, 8, (int)aConfiguringNet, asc_1DBB42, 0, 0, 0, 0, 0, 0, 0, v1); /*0x124aa3*/
    dword_1DBAAC = 1; /*0x124aa8*/
    qmemcpy((void *)(dword_1E875C + 40), v2, 0x38u); /*0x124ac4*/
  }
  return result; /*0x124ac9*/
}
