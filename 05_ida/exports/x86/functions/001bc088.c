/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc088. */
int __cdecl _NXAudioGetDeviceName(int a1, char *__dst, _DWORD *a3)
{
  id v3; // eax
  const char *v4; // eax

  if ( !a1 ) /*0x1bc097*/
    return 202; /*0x1bc0e8*/
  v3 = +[IOAudio _instance](aIoaudio, sel__instance); /*0x1bc0b3*/
  v4 = (const char *)objc_msgSend(v3, sel_name); /*0x1bc0bc*/
  strncpy(__dst, v4, 0xFFu); /*0x1bc0c6*/
  __dst[255] = 0; /*0x1bc0cb*/
  *a3 = strlen(__dst); /*0x1bc0e1*/
  return 0; /*0x1bc0f0*/
}
