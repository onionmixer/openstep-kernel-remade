
undefined4 _snd_audio_not_loaded(void)

{
  if (dword_40B2264 == 0) {
    _printf(aSounddspAudioD);
    dword_40B2264 = 1;
  }
  return 5;
}

