/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14bb40. */
int __cdecl ipc_object_copyin_type(int a1)
{
  int result; // eax

  switch ( a1 ) /*0x14bb4f*/
  {
    case 0: /*0x14bb4f*/
      result = 0; /*0x14bbb0*/
      break; /*0x14bbb5*/
    case 5: /*0x14bb4f*/
    case 16: /*0x14bb4f*/
      result = 16; /*0x14bbb8*/
      break; /*0x14bbc0*/
    case 6: /*0x14bb4f*/
    case 17: /*0x14bb4f*/
    case 19: /*0x14bb4f*/
    case 20: /*0x14bb4f*/
      result = 17; /*0x14bbd0*/
      break; /*0x14bbd8*/
    case 18: /*0x14bb4f*/
    case 21: /*0x14bb4f*/
      result = 18; /*0x14bbc4*/
      break; /*0x14bbcc*/
    default:
      panic(aIpcObjectCopyi); /*0x14bbe1*/
      return result; /*0x14bbe1*/
  }
  return result; /*0x14bbb4*/
}
