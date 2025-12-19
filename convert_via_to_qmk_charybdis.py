import json

VIA_LAYOUT_FILE_PATH = "/Users/avantol/Documents/charybdis.layout.json"

def main():
    final_output = ""

    via_layout_layers = []
    with open(VIA_LAYOUT_FILE_PATH) as f:
        via_layout_layers = json.load(f).get("layers", [])
        print(len(via_layout_layers))
        for layer in via_layout_layers:
            final_output += get_keymap_from_via_layer(layer)

    return final_output


def get_keymap_from_via_layer(layer):
    r1_l = layer[0:6]
    r2_l = layer[6:12]
    r3_l = layer[12:18]
    r4_l = layer[18:24]

    r1_r = layer[30:36]
    r1_r.reverse()
    r2_r = layer[36:42]
    r2_r.reverse()
    r3_r = layer[42:48]
    r3_r.reverse()
    r4_r = layer[48:54]
    r4_r.reverse()

    # Thumb & cluster lines (Indices as per your example and requested format)
    thumb_line_1 = "                                  KC_BTN2, KC_BTN1, KC_BTN3,         KC_DEL,  KC_ENT,"
    thumb_line_2 = (
        "                                             DF(2),  KC_SPC,         KC_BSPC"
    )

    thumb_lines = """
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_DEL, KC_ENT,
                                              DF(2), KC_SPC,    KC_BSPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯

"""

    output = "\n".join(
        [
            "  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮",
            _format_row(r1_l) + _format_row(r1_r),
            "  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤",
            _format_row(r2_l) + _format_row(r2_r),
            "  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤",
            _format_row(r3_l) + _format_row(r3_r),
            "  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤",
            _format_row(r4_l) + _format_row(r4_r),
            "  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯",
            thumb_lines,
        ]
    )

    return output


def _format_row(keys):
    return "        " + ", ".join(keys) + ","


if __name__ == "__main__":
    output = main()
    print(output)

    # TODO: You will have to manually fix the CUSTOM() to proper names and fix MACROS
