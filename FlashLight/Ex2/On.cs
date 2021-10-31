using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex2
{
    // On state 
    public class On : FlashLightState
    {
        // Retunere information om state er On eller Off
        public override bool OnOff()
        {
            return true;
        }
        // Fortæller hvilket state der er aktivt
        public override string ActiveState()
        {
            return "On";
        }
        // Handler der kaldes ved "Invoke" kald
        public override void HandlePower(object sender, IFlashLight context)
        {
            context.SetState(new Off());
        }
    }
}
