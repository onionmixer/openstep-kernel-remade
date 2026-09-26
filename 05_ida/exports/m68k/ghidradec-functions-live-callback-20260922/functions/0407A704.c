
void _od_request(void)

{
  _od_req_th = _active_threads;
  do {
    _od_requested = 0;
    do {
      _sleep(&_od_requested,0x14);
    } while (_od_requested == 0);
    if (_od_spinup == 0) {
      _od_request_vol();
    }
    while (_od_requested == 1) {
      _sleep(&_od_requested,0x14);
    }
    if (_od_alert_present == 0) {
      _alert_done();
    }
    else {
      _vol_panel_remove(_od_vol_tag);
      _od_alert_abort = 0;
      _od_alert_present = 0;
    }
  } while( true );
}

