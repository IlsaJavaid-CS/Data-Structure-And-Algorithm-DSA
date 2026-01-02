import React, { useState } from 'react'
import Title from './title'
import { testimonials } from '../assets/assets'
const Testimonials = () => {
    const [tooltip, setTooltip] = useState({ visible: false, x: 0, y: 0, text: '' });
        const cardRefs = React.useRef([]);
    
        const handleMouseMove = (e, index) => {
            const bounds = cardRefs.current[index].getBoundingClientRect();
            setTooltip({
                visible: true,
                x: e.clientX - bounds.left,
                y: e.clientY - bounds.top,
                text: testimonials[index].name,
            });
        };
    
        const handleMouseLeave = () => {
            setTooltip({ ...tooltip, visible: false });
        };
  return (
    <>
    <div className='flex flex-col items-center px-6 md:px-16 lg:px-24 pt-20 pb-10'>
        <Title title="What our guests Say" subtitle="Genuine reviews, happy memories Voices of our cherished guests Discover why guests love us Testimonials that speak for themselves"/>
        <div className="flex flex-no-wrap items-center gap-4 py-10 mt-4">
                {testimonials.map((testimonial, index) => (
                    <div key={index} ref={(el) => (cardRefs.current[index] = el)}
                        onMouseMove={(e) => handleMouseMove(e, index)}
                        onMouseLeave={handleMouseLeave}
                        className="relative border border-gray-200 rounded-lg overflow-hidden max-w-sm hover:shadow-lg transition-shadow duration-300"
                    >
                        {tooltip.visible && tooltip.text === testimonial.name && (
                            <span className="absolute px-2.5 py-1 text-sm rounded text-nowrap bg-gray-500 text-white pointer-events-none transition-all duration-300"
                                style={{ top: tooltip.y + 8, left: tooltip.x + 8, transition: 'all 0.3s ease-out', animationDelay: '0.2s', }} >
                                {tooltip.text}
                            </span>
                        )}

                        <div className="flex flex-col items-center justify-center p-8 text-center bg-gray-700/25">
                            <div className="mb-4 text-white">
                                <h3 className="text-lg font-semibold text-white">Very easy to integrate</h3>
                                <p className="my-4 text-sm line-clamp-3">{testimonial.review}</p>
                            </div>
                            <div className="flex items-center justify-center">
                                <img className="rounded-full w-9 h-9"
                                    src={testimonial.image}
                                    alt={`${testimonial.name} profile`}
                                />
                                <div className="space-y-0.5 font-medium text-left ml-3">
                                    <p>{testimonial.name}</p>
                                    <p className="text-sm text-white">{testimonial.title}</p>
                                </div>
                            </div>
                        </div>
                    </div>
                ))}
            </div>
    </div>
</>
  )
}

export default Testimonials