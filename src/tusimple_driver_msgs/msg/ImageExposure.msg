Header header


uint32  camera_number       #camera's number from 0 -> number of camera

bool    exposure_auto
float64 exposure_time       # Time duration (microseconds) the shutter was open.

bool    gain_auto
float64 gain                # Gain (in dB) applied to the images in the sequence.

bool    white_balance_auto
float64  white_balance_blue   # White balance in blue.(blue-green ratio , max:4.0)
float64  white_balance_red    # White balance in red.(red-green ratio, max 4.0)
