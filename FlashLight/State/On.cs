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
        private On _mode;
        public string _activeState = "On";
        public virtual void HandleMode(object sender, On context) {}
        public virtual bool PassType() { return false; }

        On

        public event EventHandler<On> SolidModeEvent;
        public event EventHandler<On> StrobeModeEvent;
        public override void Mode(FlashLightState e, EventHandler<On> handler)
        {

            handler?.Invoke(this, (On)e);

        }
        public void SetModeState(On mode)
        {
            _mode = mode;
        }
        public bool ModeType()
        {
            return _mode.PassType();
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
