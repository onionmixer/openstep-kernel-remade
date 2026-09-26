/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1047c8. */
int file_init()
{
  int result; // eax

  dword_1E89DC = (int)&file_list; /*0x1047cb*/
  file_list = (int)&file_list; /*0x1047d5*/
  result = zinit(36, 36 * max_file, 0, 0, aFileStructs); /*0x1047f2*/
  file_zone = result; /*0x1047f7*/
  return result; /*0x1047fe*/
}
