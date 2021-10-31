using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StatePattern
{
    // Off state
    public class Off : FlashLightState
    {
        public bool OnOffState = false;
        public string _activeState = "Off";
        // Retunere information om state er On eller Off
        public override bool OnOff()
        {
            return OnOffState;
        }
        // Fortæller hvilket state der er aktivt
        public override string ActiveState()
        {
            return _activeState;
        }
        // Handler der kaldes ved "Invoke" kald
        public override void HandlePower(object sender, IFlashLight context)
        {
            context.SetState(new On());
        }
    }
}
