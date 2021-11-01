using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StatePattern
{
    public class Strobe : On
    {
        // Sætter værdien for hvilken mode er aktiv
        private readonly bool modeType = false;
        // Event handler for at bestemme mode
        public override void HandleMode(object sender, On context)
        {
            context.SetModeState(new Solid());
        }
        // Retunere mode typen
        public override bool ModeType()
        {
            return modeType;
        }
    }
}
