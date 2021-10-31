using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static Ex2.FlashLightState;

namespace Ex2
{

    public class FlashLight : EventArgs, IFlashLight
    {
        // Opsætning af events
        public event EventHandler<IFlashLight> PowerEventOn;
        public event EventHandler<IFlashLight> PowerEventOff;

        // Opretter abstract state, der kan symbolisere de states tilknyttet FlashLightState
        FlashLightState _state;

        // Event "Invoke" metode, der aktivere eventhandler (som findes i On, Off og FlashLightState)
        public void Power(IFlashLight e, bool eventActive)
        {
            EventHandler<IFlashLight> handlerOn = PowerEventOn;
            EventHandler<IFlashLight> handlerOff = PowerEventOff;

            // Laver "Invoke" på On evenhandleren
            if (eventActive)
            {
                handlerOn?.Invoke(this, e);
                eventActive = false;
            }
            // Laver "Invoke" på Off evenhandleren
            else if (!eventActive)
            {
                handlerOff?.Invoke(this, e);
                eventActive = true;
            }
        }

        // Bestemmer init state til at være Off
        public FlashLight()
        {
            _state = new Off();
        }
        // Funktion der sætter state, hvis der skiftes til nyt
        public void SetState(FlashLightState s)
        {
            if (_state != s)
            {
                _state = s;

                // Printer hvilket state der er aktivt
                Console.WriteLine("State has changed to: {0}", _state.ActiveState());

                // Bestemmer om der skal tændes eller slukkes, alt efter hvilket state der er aktivt
                if (_state.OnOff()) {
                    LightOn();
                }
                else if (!_state.OnOff())
                {
                    LightOff();
                }
            }
        }
        // Symoblisere fysisk FlashLight og bestemmer om FlashLight er tændt eller slukket
        private static void LightOn()
        {
            Console.WriteLine("Flashlight is On!");
        }
        private static void LightOff()
        {
            Console.WriteLine("Flashlight is Off!");
        }
    }
}
