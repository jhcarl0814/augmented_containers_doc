/** @type {import('tailwindcss').Config} */
module.exports = {
    corePlugins: {
        preflight: true,
        aspectRatio: true,
    },
    content: [
        "./docs/**/*.{html,js}",
    ],
	theme: {
		extend: {},
	},
	plugins: [],
}
