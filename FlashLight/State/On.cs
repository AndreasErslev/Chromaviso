using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StatePattern
{
    // On state 
    public class On : FlashLightState
    {

        public bool OnOffState = true;
        public bool modeType = true;
        public string _activeState = "On";
        public virtual void HandleMode(object sender, On context) {}

        public override void Mode(FlashLightState e, EventHandler<On> handler)
        {

            handler?.Invoke(this, (On)e);

        }

        public void SetModeState(On o)
        {
            modeType = o.modeType;
        }

        public override bool ModeType()
        {
            return modeType;
        }
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
            context.SetState(new Off());
        }
    }
}
