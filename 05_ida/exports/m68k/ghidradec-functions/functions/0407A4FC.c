
void _od_label_alloc(void)

{
  do {
    if (_od_label == 0) {
      _od_buf_alloc();
    }
    _sleep(&_od_label,0x14);
  } while( true );
}
