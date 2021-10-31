using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex2
{
    // Off state
    public class Off : FlashLightState
    {
        // Retunere information om state er On eller Off
        public override bool OnOff()
        {
            return false;
        }
        // Fortæller hvilket state der er aktivt
        public override string ActiveState()
        {
            return "Off";
        }
        // Handler der kaldes ved "Invoke" kald
        public override void HandlePower(object sender, IFlashLight context)
        {
            context.SetState(new On());
        }
    }
}
